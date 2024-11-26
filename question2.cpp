#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// 結構體表示任務，包含任務名稱和優先級
struct Task {
    string name;
    int priority;
    
    // 構造函數初始化任務
    Task(string n, int p) : name(n), priority(p) {}
    
    // 重載 < 運算符定義基於優先級的最大堆（Max Heap）
    bool operator<(const Task& other) const {
        return priority < other.priority;  // 最大堆
    }
};

int main() {
    int N;  // 操作的數量
    cin >> N;

    priority_queue<Task> pq;  // 最大堆用來存儲任務
    vector<string> results;  // 儲存每個 GET 操作的結果

    for (int i = 0; i < N; ++i) {
        string operation;
        cin >> operation;

        if (operation == "ADD") {
            string task_name;
            int priority;
            cin >> task_name >> priority;
            pq.push(Task(task_name, priority));  // 把任務加入優先隊列
        } else if (operation == "GET") {
            if (!pq.empty()) {
                Task highest_priority_task = pq.top();  // 獲取優先級最高的任務
                results.push_back(highest_priority_task.name);  // 保存 GET 操作的結果
                pq.pop();  // 移除優先級最高的任務
            }
        }
    }

    // 輸出所有 GET 操作的結果
    for (const auto& task : results) {
        cout << task << endl;
    }

    // 把剩餘的任務存儲到向量中
    vector<Task> remaining_tasks;
    while (!pq.empty()) {
        remaining_tasks.push_back(pq.top());
        pq.pop();
    }

    // 顯示剩餘任務的名稱和優先級，按照優先級從高到低排序
    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remaining_tasks.size(); ++i) {
        cout << "('" << remaining_tasks[i].name << "', " << remaining_tasks[i].priority << ")";
        if (i != remaining_tasks.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
