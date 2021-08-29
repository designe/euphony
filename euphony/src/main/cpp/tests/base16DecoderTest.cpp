#include <gtest/gtest.h>
#include <Definitions.h>
#include <Base16.h>
#include <tuple>
#include <ASCIICharset.h>

using namespace Euphony;

typedef std::tuple<string, string> TestParamType;

class Base16DecoderTestFixture : public ::testing::TestWithParam<TestParamType> {

public:
    void openDecoder() {
        EXPECT_EQ(codec, nullptr);
        codec = new Base16();
        ASSERT_NE(codec, nullptr);
    }

    BaseCodec* codec = nullptr;
};

TEST_P(Base16DecoderTestFixture, DefaultDecodingTest)
{
    openDecoder();

    string source;
    string expectedEncodedResult;

    std::tie(source, expectedEncodedResult) = GetParam();
    expectedEncodedResult = source;

    string actualResult = codec->encode(source);
    EXPECT_EQ(actualResult, expectedEncodedResult);
}

TEST_P(Base16DecoderTestFixture, ASCIIDecodingTest)
{
    openDecoder();
    codec->setCharset(new ASCIICharset());

    string source;
    string expectedDecodedResult;

    std::tie(source, expectedDecodedResult) = GetParam();

    string actualResult = codec->decode(source);
    EXPECT_EQ(actualResult, expectedDecodedResult);
}

INSTANTIATE_TEST_SUITE_P(
        Base16DecodingTest,
        Base16DecoderTestFixture,
        ::testing::Values(
                TestParamType("61", "a"),
                TestParamType("62", "b"),
                TestParamType("63", "c"),
                TestParamType("616263", "abc"),
                TestParamType("6c6d6e6f", "lmno"),
                TestParamType("656667", "efg"),
                TestParamType("6162636465666768696a6b6c6d6e6f707172737475767778797a", "abcdefghijklmnopqrstuvwxyz"),
                TestParamType("414243", "ABC"),
                TestParamType("4142434445464748494a4b4c4d4e4f505152535455565758595a", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"),
                TestParamType("68656c6c6f2c20657570686f6e79", "hello, euphony")
));