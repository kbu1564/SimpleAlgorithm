#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	scanf("%*d");
	char str[25];
	while (~scanf("%s",str)){
		reverse(str,str+strlen(str));
		puts(str);
	}
	return 0;
}