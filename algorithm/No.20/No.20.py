import math
# STEP 0) "입력 및 초기화" 반복횟수  T를 초기화한다.
T = int(input())
# STEP 1) "반복" T 횟수만큼 반복한다.
while T>0:
    # STEP 1-1) "입력 및 변수 초기화" x, y값을 초기화
    #           장치작동회수를 나타내는 count 변수와 거리를 나타내는 dist 변수 초기화
    x, y = input().split()
    dist = int(y) - int(x)
    if dist <= 3: # 거리가 3 이하는 그대로 출력
        print(dist)
    else:
        n = int(math.sqrt(dist)) # 제곱근을 구하기
        if dist == n ** 2: # 거리가 N의 제곱 일때
            print(2*n-1) 
        elif n ** 2 < dist <= n ** 2 + n: # 거리가 N의제곱+N 이하
            print(2*n)
        else: # 거리가 N의제곱+N 초과
            print(2*n+1)
    T -=1
