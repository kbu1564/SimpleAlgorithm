## Brew 를 이용한 라이브러리 설치
* galib 2.4.7 버전 사용
	* brew install galib

## 컴파일 옵션
* brew 이용하여 설치시 기본 경로가 /usr/local 로 셋팅되야 하므로 라이브러리와 include path 지정
	* g++ 소스파일명 -I /usr/local/include -L /usr/local/lib -lm -lga
