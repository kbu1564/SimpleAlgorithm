#include <cstdio>

int main() {
	while (1) {
		char S[81] = { 0, };
		gets(S);
		if (S[0] == 'E' && S[1] == 'O' && S[2] == 'I') break;		

		for (int i = 0; S[i]; i++) if (S[i] >= 'A' && S[i] <= 'Z') S[i] = 'a' + (S[i] - 'A');
		printf("%s\n", S);

		bool isFind = false;
		int isn = 0, ise = 0, ism = 0, iso = 0;
		for (int i = 0; S[i]; i++) {
			if (S[i] != 'n' && S[i] != 'e' && S[i] != 'm' && S[i] != 'o') {
				isn = ise = ism = iso = 0;
				continue;
			}
			if (isn + ise + ism + iso == 0 && S[i] == 'n') isn = 1;
			if (isn == 1 && ise + ism + iso == 0 && S[i] == 'e') ise = 1;
			if (isn + ise == 2 && ism + iso == 0 && S[i] == 'm') ism = 1;
			if (isn + ise + ism == 3 && iso == 0 && S[i] == 'o') {
				iso = 1;
				isFind = true;
				break;
			}
		}
		printf("%s\n", (isFind == true? "Found": "Missing"));
	}
	return 0;
}
