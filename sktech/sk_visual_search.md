# SK Planet Visual Search
* 손쉬운 상품 검색을 위한 Visual Search
* 영상처리
	- 영상을 Query로 검색처리

## 사전 지식
* Deep Learning
	- Deep Artificial Neural Network + Machine Learning

1. 카테고리 예측
	- Deep Learning
	- 이 단계가 실패할 경우 이후 과정에 문제 발생
		- 세분화 단계 확대
1. 관심영역 추출
	- Grab-cut Saliency - HoG + SVM 을 이용한 검증
	- 상 하의 색상이 같은 경우 하나의 옷으로 분류되는 문제 발생
1. 특징 추출

* 기존 시스템
	- 진짜 잘되는 것의 기준은?
	- 배경이 단순해야함
	- 영상만으로는 사용자의 목적 파악 불가능
	- 유사상품의 정의 불가능
* 해결책
	- Deep Learning 기반의 Detection 기술 적용

## 기술 소개
1. Detection
	- RPN을 CNN 이후에 적용
	- 관련논문 : Faster R-CNN - NIPS 2015
1. Feature - 특징추출
	- Deep Learning 기반 - Deep feature
	- 유사상품에 대한 Ground truth를 만드는게 매우 어려움
		- UkBench Dataset 기반으로 테스트 진행
	- CNN 을 거치기 전과 후의 결과를 합성
		- 대량의 학습시간 필요
1. Attribute Classifier
	- 동일 속성을 중점적으로 알고리즘 고안 시작
	- SK Planet 에서 90가지 속성을 분류하여 DB화 하는데 100 man-month 소요
		- ROI DB 구축
	- Multi-label Classification
		- RNN 으로 접근 가능하도록 하기위해 상위 레벨의 정보가 하위레벨에 관련을 가지도록 구성
1. Guided Search
	- 특정 영상을 쿼리로 넣었을 때 영상으로는 파악이 불가능
	- 사용자가 검색되기 원하는 상품을 선택하도록 함
		- 판매자의 태그 정보가 정제되어 있지 않음
		- 해결책으로 자연어 처리 기술의 도입
			- 형태소 분석을 통한 동의어 처리 및 판단
1. 전체 검색 시스템
	- 90차원(가지)의 속성을 인덱스로 사용
	- 분산시스템으로 구축해 보니 알아낸 문제점
		- 검색대상이 너무 많음
		- 데이터베이스 관리가 매우 어려움
		- 해결책 : SK 내부의 분산처리 솔루션 사용
			- Redis 기반의 분산 인 메모리 기반 병렬 처리 기술 적용

## QnA
1. 실제 매출에 영향이 있었나?
	- 현재 적용한게 아니라 알수 없다.
1. 따로 준비한 데이터가 있나?
	- 이미 학습된 100만장의 데이터가 있어서 이걸 기반했다.
