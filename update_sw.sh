mv sw/src/main.cpp .
rm -d -r sw/src
cp tests/src/sw sw -r
mv sw/sw sw/src
mv main.cpp sw/src/
