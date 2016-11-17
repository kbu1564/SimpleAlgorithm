/*
가장 간단한 유전 알고리즘
A Simple Genetic Algorithm

1. 점수가 최대인 값을 우월 유전자로 판단
2. N 개의 유전자를 랜덤하게 생성
3.1. 2개의 유전자를 선택하되 선택된 유전자 유지(보통 유전자점수/총점 의 확률로 선택)
3.2. 2개의 유전자를 교배(Crossover) 하여 새로운 유전자를 생성(보통 2개 새로 생성)
3.3. 돌연변이(Mutation) 생성 - 높지는 않은 확률로 실행(보통 0.001% 등 매우 낮은 발생확률로 책정)
4. 생성된 유전자들을 다음세대 자손으로 추가
5. 2번으로 반복 - 이전 부모자손 제거

알고리즘 적용시
1. 여러개의 숫자로 표현될 유전자의 표현 방법 설계 - 유전자 설계
*/