/*
 * 文件名: ThreadPoll.c
 * 作者: ljk
 * 创建时间: 2023-07-26
 * 文件描述: 线程池操作例程
 */
#include <stdlib.h>
#include <pthread.h>     
#include <stdio.h>
#include "ThreadPool.h"


#define THREAD_POOL_SIZE 5

typedef struct {
    void (*function)(void *arg);
    void *arg;
} Task;

typedef struct {
    Task *tasks;
    int capacity;
    int size;
    int front;
    int rear;
    pthread_mutex_t mutex;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;
} ThreadPool;
static ThreadPool *pool;

// 线程池初始化
void initThreadPool(int capacity) 
{
    pool = (ThreadPool *)malloc(sizeof(ThreadPool));
    pool->tasks = (Task *)malloc(sizeof(Task) * capacity);
    pool->capacity = capacity;
    pool->size = 0;
    pool->front = 0;
    pool->rear = 0;
    pthread_mutex_init(&pool->mutex, NULL);
    pthread_cond_init(&pool->not_full, NULL);
    pthread_cond_init(&pool->not_empty, NULL);
}

// 添加任务
void addTask(void (*function)(void *arg), void *arg) 
{
    pthread_mutex_lock(&pool->mutex);
    while (pool->size == pool->capacity) {
        pthread_cond_wait(&pool->not_full, &pool->mutex);
    }

    pool->tasks[pool->rear].function = function;
    pool->tasks[pool->rear].arg = arg;
    pool->rear = (pool->rear + 1) % pool->capacity;
    pool->size++;

    pthread_cond_signal(&pool->not_empty);
    pthread_mutex_unlock(&pool->mutex);
}

// 线程池执行
void *executeTask(void *arg) {
    while (1) {
        pthread_mutex_lock(&pool->mutex);
        while (pool->size == 0) {
            pthread_cond_wait(&pool->not_empty, &pool->mutex);
        }

        Task task = pool->tasks[pool->front];
        pool->front = (pool->front + 1) % pool->capacity;
        pool->size--;

        pthread_cond_signal(&pool->not_full);
        pthread_mutex_unlock(&pool->mutex);

        (task.function)(task.arg);
    }

    return NULL;
}

// 任务
void taskFunction(void*  idx)
{
    printf(" --task-- %d\n", *(int*)idx);
}


// 测试程序
int main(int argc, char* argv) {
    initThreadPool(THREAD_POOL_SIZE);

    printf("创建线程\n");
    // 创建线程并执行任务
    pthread_t threads[THREAD_POOL_SIZE];
    for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_create(&threads[i], NULL, executeTask, NULL);
    }
    printf("任务执行\n");


     // 添加任务到线程池
    for (int i = 0; i < 100; i++) {
        int *arg = (int *)malloc(sizeof(int));
        *arg = i;
        printf("添加任务:%d\n", *arg);
        addTask(taskFunction, arg);
    }

    // 等待所有线程完成
    for (int i = 0; i < THREAD_POOL_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
