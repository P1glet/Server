/*
 * @Author: P1glet 
 * @Date: 2022-05-03 15:08:45 
 * @Last Modified by:   P1glet 
 * @Last Modified time: 2022-05-03 15:08:45 
 */
#include"TaskQueue.h"

TaskQueue::Task TaskQueue::takeTask() {
    Task task;
    std::lock_guard<std::mutex> lockGuard(taskQueueMutex);  // 上锁
    if (!taskQueue.empty()) {
        task = std::move(taskQueue.front());    // 取出任务
        taskQueue.pop();  // 将任务从队列中删除
        return task;
    }
    return nullptr;
}