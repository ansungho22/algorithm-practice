# 에라토스테네스의 체 알고리즘
# N은 2*123456보다 작기때문에 2*123456보다 작은 소수의 리스트를 생성한다.
N = 123456 * 2
sieve = [True] * (N + 1)
ans = []
# True : 소수, False : 소수아님. 초기화 : True

for i in range(2, int(N ** 0.5) + 1):
    # n의 최대 약수가 sqrt(n) 이하이므로 i=sqrt(n)까지 검사
    if sieve[i] == True:
        for j in range(i * 2, N + 1, i):
            sieve[j] = False

# STEP 0 ) N을 입력받아 초기화한다.
while True:
    cnt = 0
    n = int(input())
    # STEP 1 ) N이 0 이라면 종료한다.
    if n == 0:
        break
    else:
        # STEP 2 ) N부터 2N까지의 소수가있는지 sieve가 참이라면 카운트한다.
        #         참이라는것은 소수를 뜻한다.
        cnt = 0
        for i in range(n + 1, n * 2 + 1):
            if sieve[i]:
                cnt += 1
    ans.append(cnt)

print(ans)
