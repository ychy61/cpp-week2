#include <iostream>
#include <random>
#include <chrono>

bool game(int answer, int guess); // 게임 로직 함수

int util(){
      int answer; // 정답을 저장할 변수
      std::cout << "Enter a answer: ";
      std::cin >> answer; // 정답을 입력 받음

      int guess; // 추측할 수
      int success = false;
      while(success != true){ // success 변수가 true가 아닐때까지 수행
            std::cout << "Enter a guess: ";
            std::cin >> guess; //추측할 수를 입력 받음

            success = game(answer, guess); // 게임 로직 함수 호출하고 반환되는 값을 success로 받음
      }

      return 0;
}