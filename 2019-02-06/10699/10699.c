#include <stdio.h>
#include <time.h>


void main(void) {
  time_t timer;
  struct tm *t;

  timer = time(NULL); // 현재 시각을 초 단위로 얻기

  t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기

  printf("현재 년: %d\n",   t->tm_year + 1900);
  printf("현재 월: %d\n",   t->tm_mon + 1);
  printf("현재 일: %d\n\n", t->tm_mday);

  printf("현재 시: %d\n",   t->tm_hour);
  printf("현재 분: %d\n",   t->tm_min);
  printf("현재 초: %d\n\n", t->tm_sec);

  printf("현재 요일: %d\n", t->tm_wday); // 일요일=0, 월요일=1, 화요일=2, 수요일=3, 목요일=4, 금요일=5, 토요일=6
  printf("올해 몇 번째 날: %d\n", t->tm_yday); // 1월 1일은 0, 1월 2일은 1
  printf("서머타임 적용 여부: %d\n", t->tm_isdst); // 0 이면 서머타임 없음

}