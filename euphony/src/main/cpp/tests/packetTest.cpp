#include <gtest/gtest.h>
#include <Definitions.h>
#include <Packet.h>
#include <tuple>
#include <ASCIICharset.h>

using namespace Euphony;

typedef std::tuple<std::string, std::string> TestParamType;

class PacketTestFixture : public ::testing::TestWithParam<TestParamType> {

public:
    Packet* pkt = nullptr;
};

TEST_P(PacketTestFixture, PacketCreationForASCIITest)
{
    std::string source;
    std::string expectedResult;

    std::tie(source, expectedResult) = GetParam();

    HexVector hv = ASCIICharset().encode(source);
    pkt = new Packet(hv);

    // Check total result
    EXPECT_EQ(pkt->toString(), expectedResult);
}

INSTANTIATE_TEST_CASE_P(
        PacketTestSuite,
        PacketTestFixture,
        ::testing::Values(
                TestParamType("a", "S6197"),
                TestParamType("b", "S6284"),
                TestParamType("c", "S6375"),
                TestParamType("abc", "S61626386"),
                TestParamType("lmno", "S6c6d6e6f20"),
                TestParamType("efg", "S656667c2"),
                TestParamType("abcdefghijklmnopqrstuvwxyz", "S6162636465666768696a6b6c6d6e6f707172737475767778797aaa"),
                TestParamType("ABC", "S414243e4"),
                TestParamType("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "S4142434445464748494a4b4c4d4e4f505152535455565758595aea")
        ));