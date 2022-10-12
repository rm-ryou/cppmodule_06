RED="\e[31m"
GREEN="\e[32m"
NORMAL="\e[m"

./convert 0 > ./test/test_0
DIF=$(diff ./test/ans/0 ./test/test_0)
if [ "$DIF" = "" ]; then
	echo -e "${GREEN}diff ok${NORMAL}"
else
	echo -e "${RED}failed 0${NORMAL}"
fi

./convert nan > ./test/test_nan
DIF=$(diff ./test/ans/nan ./test/test_nan)
if [ "$DIF" = "" ]; then
	echo -e "${GREEN}diff ok${NORMAL}"
else
	echo -e "${RED}failed nan${NORMAL}"
fi

./convert 42.0f > ./test/test_42.0f
DIF=$(diff ./test/ans/42.0f ./test/test_42.0f)
if [ "$DIF" = "" ]; then
	echo -e "${GREEN}diff ok${NORMAL}"
else
	echo -e "${RED}failed 42.0f${NORMAL}"
fi

./convert 42.42 > ./test/test_42.42
DIF=$(diff ./test/ans/42.42 ./test/test_42.42)
if [ "$DIF" = "" ]; then
	echo -e "${GREEN}diff ok${NORMAL}"
else
	echo -e "${RED}failed 42.42${NORMAL}"
fi

./convert 42.42.42 > ./test/test_42.42.42
DIF=$(diff ./test/ans/42.42.42 ./test/test_42.42.42)
if [ "$DIF" = "" ]; then
	echo -e "${GREEN}diff ok${NORMAL}"
else
	echo -e "${RED}failed 42.42.42${NORMAL}"
fi

./convert 42.42ff > ./test/test_42.42ff
DIF=$(diff ./test/ans/42.42ff ./test/test_42.42ff)
if [ "$DIF" = "" ]; then
	echo -e "${GREEN}diff ok${NORMAL}"
else
	echo -e "${RED}failed 42.42ff${NORMAL}"
fi

./convert 42.42f > ./test/test_42.42f
DIF=$(diff ./test/ans/42.42f ./test/test_42.42f)
if [ "$DIF" = "" ]; then
	echo -e "${GREEN}diff ok${NORMAL}"
else
	echo -e "${RED}failed 42.42f${NORMAL}"
fi

./convert 126 > ./test/test_126
DIF=$(diff ./test/ans/126 ./test/test_126)
if [ "$DIF" = "" ]; then
	echo -e "${GREEN}diff ok${NORMAL}"
else
	echo -e "${RED}failed 126${NORMAL}"
fi

./convert -1 > ./test/test_-1
DIF=$(diff ./test/ans/-1 ./test/test_-1)
if [ "$DIF" = "" ]; then
	echo -e "${GREEN}diff ok${NORMAL}"
else
	echo -e "${RED}failed -1${NORMAL}"
fi

./convert 65 > ./test/test_65
DIF=$(diff ./test/ans/65 ./test/test_65)
if [ "$DIF" = "" ]; then
	echo -e "${GREEN}diff ok${NORMAL}"
else
	echo -e "${RED}failed${NORMAL}"
fi

./convert 2147483649 > ./test/test_2147483649
DIF=$(diff ./test/ans/2147483649 ./test/test_2147483649)
if [ "$DIF" = "" ]; then
	echo -e "${GREEN}diff ok${NORMAL}"
else
	echo -e "${RED}failed${NORMAL}"
fi

./convert 340282346638528859811704183484516925440.000000f > ./test/test_340282346638528859811704183484516925440.000000f
DIF=$(diff ./test/ans/340282346638528859811704183484516925440.000000f ./test/test_340282346638528859811704183484516925440.000000f)
if [ "$DIF" = "" ]; then
	echo -e "${GREEN}diff ok${NORMAL}"
else
	echo -e "${RED}failed${NORMAL}"
fi

./convert + > ./test/test_+
DIF=$(diff ./test/ans/+ ./test/test_+)
if [ "$DIF" = "" ]; then
	echo -e "${GREEN}diff ok${NORMAL}"
else
	echo -e "${RED}failed '+'${NORMAL}"
fi

rm -f ./test/test_*