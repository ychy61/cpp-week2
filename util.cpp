#include <iostream>
#include <random>
#include <chrono>

bool game(int answer, int guess); // 게임 로직 함수

// 정답 숫자를 랜덤으로 생성하는 함수
int makeAnswer(){

      // 현재 시간을 기반으로 시드값을 생성
      unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

      // 생성된 시드값을 이용하여 무작위 수 생성 엔진을 초기화
      std::mt19937 gen(seed);

      // 100부터 999까지의 균등 분포 정의
      std::uniform_int_distribution<int> dis(100, 999);

      int answer = dis(gen);

      //중복이 있다면 함수를 다시 호출
      if (answer/100 == (answer%100)/10 | answer/100 == answer%10 | (answer%100)/10 == answer%10){
            answer = makeAnswer();
      }

      return answer;
}

int util(){
      int answer = makeAnswer();
      std::cout << "Answer is " << answer << std::endl;

      int guess; // 추측할 수
      int success = false;
      while(success != true){ // success 변수가 true가 아닐때까지 수행
            std::cout << "Enter a guess: ";
            std::cin >> guess; //추측할 수를 입력 받음

            success = game(answer, guess); // 게임 로직 함수 호출하고 반환되는 값을 success로 받음
      }

      return 0;
}