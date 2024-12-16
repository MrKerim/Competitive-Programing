class Solution:

    def encode(self, strs: List[str]) -> str:
        encodedString = ""
        for s in strs:
            encodedString += f"{len(s)}:{s}"
        return encodedString

    def decode(self, s: str) -> List[str]:
        decodedStrings = []
        number = ""
        i = 0
        while(i < len(s)):
            if(s[i] != ":"):
                number += s[i]
                i += 1
            else:
                decodedStrings.append(s[i+1:i+1+int(number)])
                i += int(number) + 1
                number = ""

        return decodedStrings