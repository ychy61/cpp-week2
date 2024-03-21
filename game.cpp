#include <iostream>

int ballCount;
int strikeCount;

//게임 로직 - 게임 흐름, 스트라이크, 볼 처리

//ball수를 count하는 함수
int ball(int answer, int guess){
      int ballCount = 0;
      int answer_100  = answer/100, guess_100 = guess/100;
      int answer_10 = (answer%100)/10, guess_10 = (guess%100/10);
      int answer_1 = answer%10, guess_1 = guess%10;

      if(answer_100 == guess_10 || answer_100 == guess_1){
            ballCount += 1;
      }
      if(answer_10 == guess_100 || answer_10 == guess_1){
            ballCount += 1;
      }
      if(answer_1 == guess_100 || answer_1 == guess_10){
            ballCount += 1;
      }
      return ballCount;
}

//strike수를 count하는 함수
int strike(int answer, int guess){
      int strikeCount=0;

      //100의 자리 비교
      if(answer/100 == guess/100){
            strikeCount += 1;
      }
      //10의 자리 비교
      if((answer%100)/10 == (guess%100)/10){
            strikeCount += 1;
      }
      //1의 자리 비교
      if((answer%10 == guess%10)){
            strikeCount += 1;
      }

      return strikeCount;
}

bool game(int answer, int guess){
      ballCount = ball(answer, guess);
      strikeCount = strike(answer, guess);

      if (strikeCount == 3){
            std::cout << "You win"<<std::endl;
            return true;
      } else {
            std::cout << "Strikes: "<<strikeCount<<", Balls: "<<ballCount<<std::endl;
            return false;
      }
};