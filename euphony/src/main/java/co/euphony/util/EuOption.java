package co.euphony.util;

public class EuOption {

    // RX & TX Common Variables
    private int mSampleRate;
    private int mFFTSize;
    private int mBufferSize;
    private int mFadeRange;
    private int mOutsetFrequency;
    private int mControlPoint;
    private int mDataRate;
    private int mDataInterval;

    // RX Only
    private int mMaxReference;
    private int mMinReference;
    private int mDefaultReference;

    // Detect Mode
    private int mDetectFrequency;

    private void initCommonVariables() {
        // TX & RX Common Variables Setting
        mSampleRate = 44100;
        mFFTSize = 512;
        mBufferSize = 2048;
        mFadeRange = 512; // to apply fadein fadeout range
        mControlPoint = 18017;
        mDataRate = 16;
        mDataInterval = mSampleRate / mFFTSize;
        mOutsetFrequency = mControlPoint - mDataInterval;

        // RX Setting
        mMaxReference = 4000;
        mMinReference = 50;
        mDefaultReference = 500;
    }

    public EuOption() {
        initCommonVariables();
    }

    public int getSampleRate() {
        return mSampleRate;
    }

    public void setSampleRate(int _sampleRate) {
        this.mSampleRate = _sampleRate;
    }

    public int getFFTSize() {
        return mFFTSize;
    }

    public void setFFTSize(int _FFTSize) {
        this.mFFTSize = _FFTSize;
    }

    public int getBufferSize() {
        return mBufferSize;
    }

    public void setBufferSize(int _bufferSize) {
        this.mBufferSize = _bufferSize;
    }

    public int getFadeRange() {
        return mFadeRange;
    }

    public void setFadeRange(int _fadeRange) {
        this.mFadeRange = _fadeRange;
    }

    public int getOutsetFrequency() {
        return mOutsetFrequency;
    }

    public void setOutsetFrequency(int _outsetFrequency) {
        this.mOutsetFrequency = _outsetFrequency;
    }

    public int getDataRate() {
        return mDataRate;
    }

    public void setDataRate(int _dataRate) {
        this.mDataRate = _dataRate;
    }

    public int getDataInterval() {
        return mDataInterval;
    }

    public void setDataInterval(int _dataInterval) {
        this.mDataInterval = _dataInterval;
    }

    public int getMaxReference() {
        return mMaxReference;
    }

    public void setMaxReference(int _maxReference) {
        this.mMaxReference = _maxReference;
    }

    public int getMinReference() {
        return mMinReference;
    }

    public void setMinReference(int _minReference) {
        this.mMinReference = _minReference;
    }

    public int getDefaultReference() {
        return mDefaultReference;
    }

    public void setDefaultReference(int _defaultReference) {
        this.mDefaultReference = _defaultReference;
    }

    public int getControlPoint() {
        return mControlPoint;
    }

    public void setControlPoint(int _controlPoint) {
        this.mControlPoint = _controlPoint;
    }

    public int getDetectFrequency() {
        return mDetectFrequency;
    }

    public void setDetectFrequency(int mDetectFrequency) {
        this.mDetectFrequency = mDetectFrequency;
    }

}
