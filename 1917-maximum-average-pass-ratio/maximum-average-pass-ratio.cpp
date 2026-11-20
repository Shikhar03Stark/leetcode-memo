class Solution {
public:

    double get_potential(int passed, int total) {
        double ratio = (1.0*passed) / total;
        return (1 - ratio) / (1.0 + total);
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double, int, int>> pq;
        for(auto& e: classes) {
            int passed = e[0], total = e[1];
            double potential = get_potential(passed, total);
            pq.push(make_tuple(potential, passed, total));
        }

        for(int i = 0; i<extraStudents; i++) {
            auto t = pq.top();
            // cout << "picked " << get<1>(t) << "/" << get<2>(t) << " " << get<0>(t) << '\n';
            pq.pop();
            int p = get<1>(t), tot = get<2>(t);
            double potential = get_potential(p+1, tot+1);
            pq.push(make_tuple(potential, p+1, tot+1));
        }

        double ans = 0;
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            ans += (1.0*get<1>(t)) / (get<2>(t));
        }
        return ans / classes.size();
    }
};