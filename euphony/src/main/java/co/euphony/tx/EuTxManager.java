package co.euphony.tx;

import android.content.Context;
import android.os.Handler;
import android.os.Looper;

import co.euphony.util.EuOption;
import co.euphony.util.EuSetting;

public class EuTxManager {
	private EuphonyTx txCore;
	private EuOption mTxOption = null;
	private String genCode = "";

	public enum EuPIDuration {
		LENGTH_SHORT,
		LENGTH_LONG,
		LENGTH_FOREVER
	}

	public EuTxManager(Context context) {
		txCore = new EuphonyTx(context);
	}

	public void setOption(EuOption option) {
        mTxOption = option;
	}

	/*
	 * @deprecated Replaced by {@link #setCode()}, deprecated for naming & dynamic option.
	 */
	@Deprecated
	public void euInitTransmit(String data) {
		setCode(data);
	}

	public void setCode(String data)
	{
		txCore.setCode(data);
	}

	public String getCode() {
		return txCore.getCode();
	}

	public void callEuPI(double freq, EuPIDuration duration) {
		txCore.setMode(EuSetting.ModeType.EUPI);
		txCore.setAudioFrequency(freq);
		txCore.start();
		txCore.setToneOn(true);

		if (duration != EuPIDuration.LENGTH_FOREVER) {
			new Handler(Looper.getMainLooper()).postDelayed(() -> {
						txCore.setToneOn(false);
						txCore.stop();
					},
					(duration == EuPIDuration.LENGTH_SHORT) ? 200 : 500);
		}
	}

	public String getGenCode() {
		return txCore.getGenCode();
	}

	public short[] getOutStream() {

		/* TODO: legacy code will be removed.
		    That will be bring from EuphonyTx.
		return mOutStream;
		 */
		return null;
	}

	public void play() {
		play(1);
	}

	public void play(int count) {
		txCore.setMode(EuSetting.ModeType.DEFAULT);
		txCore.start();
		txCore.setCountToneOn(true, count);
	}

	/*
	 * @deprecated Replaced by {@link #setCode()}, deprecated for naming issue
	 */
	@Deprecated
	public void process() { play(1); }

	/*
	 * @deprecated Replaced by {@link #setCode()}, deprecated for naming issue
	 */
	@Deprecated
	public void process(int count) { play(count); }

	public void stop()
	{
		txCore.setToneOn(false);
		txCore.stop();
	}
}
