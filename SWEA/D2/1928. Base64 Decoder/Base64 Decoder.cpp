#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> code = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/' };

int main() {
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		// 3byte 문자로 이루어진 원문
		// 3byte는 bit로 표현하면 24bit
		// 24bit를 6bit씩 4개로 나누어서 표현한 것이 Base64 인코딩
		// 디코딩은 4자리씩 읽어서 이를 인코딩한 3개의 문자로 변환
		
		string encoded;
		cin >> encoded;

		string byte;
		for (int j = 0; j < encoded.size(); j += 4) {
			
			for (int k = j; k < j + 4; k++) {
				int bit = find(code.begin(), code.end(), encoded[k]) - code.begin();
				for (int l = 32; l != 0; l /= 2) {
					if (bit - l >= 0) {
						byte += '1';
						bit -= l;
					} else {
						byte += '0';
					}
				}
			}
		}

		string plain_text;
		for (int j = 0; j < byte.size(); j += 8) {
			int ascii = 0;
			for (int k = j; k < j + 8; k++) {
				ascii += (byte[k] - '0') * (1 << (7 - (k % 8)));
			}
			plain_text += (char)ascii;
		}

		cout << "#" << i + 1 << " " << plain_text << endl;
	}
}