class Solution {
public:
    string decodeAtIndex(std::string inputString, int k) {

        long long decodedLength = 0;
        for (auto character : inputString) {
            if (isdigit(character)) {
                decodedLength *= character - '0';
            } else {
                decodedLength++;
            }
        }

        for (int i = inputString.size() - 1; i >= 0; i--) {
            if (isdigit(inputString[i])) {
                decodedLength /= (inputString[i] - '0');
                k = k % decodedLength;
            } else {
                if (k == 0 || decodedLength == k)
                    return string("") + inputString[i]; 
                decodedLength--;
            }
        }
        return ""; 
    }
};