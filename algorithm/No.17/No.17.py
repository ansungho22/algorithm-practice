#에라토스테네스의 체 알고리즘
def prime_list(n):
  sieve=[True] * (n+1)
  #True : 소수, False : 소수아님. 초기화 : True

  for i in range(2, int(n ** 0.5)+1):
    # n의 최대 약수가 sqrt(n) 이하이므로 i=sqrt(n)까지 검사
    if sieve[i] == True:
      for j in range(i*2, n+1 , i):
        sieve[j]=False
  return [i for i in range(2,n+1) if sieve[i]==True]
#최적의 답은 입력받은 수의 절반이 두번 반복되는거기 때문에 처음 비교 숫자는 입력받은 수의 절반이하가되어야한다.
#STEP 0 ) T를 입력받아 초기화하고 두 소수를 저장할 리스트 초기화한다.
T = int(input())
ans = []
while True :
   if T == 0:
       break
   #STEP 1 ) N에 입력받은 짝수를 초기화한다.
   N = int(input())
   N_prime = prime_list(N) #STEP 1-1)입력받은 짝수보다 작은 소수리스트 생성한다.
   N_size = len(N_prime)-1
   flag = True #STEP 1-2 ) 크기가 가장 작은 수를 구하기 위한 flag를 생성한다.
   for i in range(N_size,0,-1):
       #STEP 1-3 ) 소수리스트중 입력 받은 N의 절반이하인 자연수를 부터 비교를한다.
       if N_prime[i] <= N/2 and flag == True:
           #STEP 1-4 ) 입력받은 자연수의 절반보다 같거나 작은 소수이면서 깃발이 true라면 비교를한다.
         for j in range(N_size,0,-1):
             #STEP 1-5 ) 두개의 소수의 합이 입력받은 자연수와 같다면 ans에 추가한다.
            if N_prime[i]+N_prime[j] == N:
                    ans.append(N_prime[i])
                    ans.append(N_prime[j])
                    flag = False
   T -= 1
for i in range(0,len(ans),2):
    print(ans[i]," ",ans[i+1])








































