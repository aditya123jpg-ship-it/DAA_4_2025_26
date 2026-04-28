#include<bits/stdc++.h>
using namespace std;

struct Job {
	string id;
	int deadline;
	int profit;
};

bool compareJob(const Job &a, const Job &b) {
	return a.profit > b.profit;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	if (!(cin >> n)) {
		return 0;
	}

	vector<Job> jobs(n);
	int maxDeadline = 0;
	for (int i = 0; i < n; ++i) {
		cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
		maxDeadline = max(maxDeadline, jobs[i].deadline);
	}

	sort(jobs.begin(), jobs.end(), compareJob);

	vector<string> slot(maxDeadline + 1, "");
	int totalProfit = 0;
	int jobCount = 0;

	for (const auto &job : jobs) {
		for (int time = min(maxDeadline, job.deadline); time >= 1; --time) {
			if (slot[time].empty()) {
				slot[time] = job.id;
				totalProfit += job.profit;
				++jobCount;
				break;
			}
		}
	}

	cout << jobCount << ' ' << totalProfit << '\n';
	for (int time = 1; time <= maxDeadline; ++time) {
		if (!slot[time].empty()) {
			cout << slot[time] << ' ';
		}
	}
	cout << '\n';
	return 0;
}