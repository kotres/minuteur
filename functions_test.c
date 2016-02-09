#include "functions_test.h"

//test of function in time_type.c

void test_of_time_type(void)
{
  puts("test of time_type_valid");
  time_type type=second;
  if(time_type_valid(type)==0)
    puts("second KO");
  type=minute;
  if(time_type_valid(type)==0)
    puts("minute KO");
  type=hour;
  if(time_type_valid(type)==0)
    puts("hour KO");
  int i=3;
  for(i=3;i<20;i++){
    if(time_type_valid(i)==1)
      printf("%d KO\n",i);
  }
}

//test of functions in time_piece.c

//test of time_piece_valid
void test_time_piece_valid(void)
{
  puts("test of time_piece_valid");
  time_piece tp;
  time_piece *ptp=&tp;
  ptp->type=second;
  ptp->value=25;
  if(time_piece_valid(ptp)==0)
    puts("second KO");
  ptp->value=100;
  if(time_piece_valid(ptp)==1)
    puts("second KO");
  ptp->type=minute;
  if(time_piece_valid(ptp)==1)
    puts("minute KO");
  ptp->value=25;
  if(time_piece_valid(ptp)==0)
    puts("minute KO");
  ptp->type=hour;
  if(time_piece_valid(ptp)==1)
    puts("hour KO");
  ptp->value=10;
  if(time_piece_valid(ptp)==0)
    puts("second KO");
}

//test of time_piece_set
void test_time_piece_set(void)
{
  puts("test of time_piece_set");
  time_piece tp;
  time_piece *ptp=&tp;
  time_piece_set(ptp,32,second);
  if(ptp->value!=32)
    puts("time_piece_set value KO");
  if(ptp->type!=second)
    puts("time_piece_set type KO");
}

// test of time_piece_initalize
void test_time_piece_initalize(void)
{
  puts("test of time_piece_initalize");
  time_piece tp;
  time_piece *ptp=&tp;
  time_piece_initalize(ptp);
  if(ptp->type!=second)
    puts("time_piece_initalize type KO");
  if(ptp->value!=0)
    puts("time_piece_initalize value KO");
}

// test of time_piece_set_hour
void test_time_piece_set_hour(void)
{
  puts("test of time_piece_set_hour");
  time_piece tp;
  time_piece *ptp=&tp;
  int i=0;
  for(i=0;i<13;i++){
    time_piece_set_hour(ptp,i);
    if(ptp->type!=hour)
      printf("time_piece_set_hour type KO i=%d\n",i);
    if(ptp->value!=i)
      printf("time_piece_set_hour value KO i=%d\n",i);
  }
}

//test function
void test_function(void)
{
  test_of_time_type();
  test_time_piece_valid();
  test_time_piece_initalize();
  test_time_piece_set();
  test_time_piece_set_hour();
}
