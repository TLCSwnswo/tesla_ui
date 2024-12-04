#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H

#include <pthread.h>

// 데이터 구조 정의
typedef struct {
    float ultrasonic_distance;
    float temperature;
    float humidity;
    float pressure;
    int door_status;
    int window_status;
} Zone1_3_Data_recv;

typedef struct {
    int ID;
    float co2;
    float heart;
    int sleep_score;
} Zone2_Data_recv;

typedef struct {
    float window_command;
} Zone1_3_Data_send;

typedef struct {
    pthread_mutex_t mutex;          // 동기화를 위한 뮤텍스
    Zone1_3_Data_recv zone1_recv;   // Zone 1 데이터
    Zone1_3_Data_recv zone3_recv;   // Zone 3 데이터
    Zone2_Data_recv zone2_recv;     // Zone 2 데이터
    Zone1_3_Data_send zone1_send;   // Zone 1 전송 데이터
    Zone1_3_Data_send zone3_send;   // Zone 3 전송 데이터
} SharedMemory;

void initialize_shared_memory(SharedMemory **shared_memory);

#endif // SHAREDMEMORY_H