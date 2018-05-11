#pragma once
// This program was written by jaehyunp and distributed under the MIT license.
// Taken from: https://github.com/jaehyunp/stanfordacm/blob/master/code/

// It has been slightly modified (modernized to C++, mainly) by mraggi

#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using ll = std::int64_t;

struct Edge
{
    ll from, to, cap, flow, index_of_twin;
    Edge(ll from, ll to, ll cap, ll flow, ll index_of_twin)
        : from(from), to(to), cap(cap), flow(flow), index_of_twin(index_of_twin)
    {}
};

class PushRelabel
{
public:
    PushRelabel(ll N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N)
    {}

    void AddEdge(ll from, ll to, ll cap)
    {
        G[from].emplace_back(from, to, cap, 0, G[to].size());

        if (from == to)
            ++G[from].back().index_of_twin;

        G[to].emplace_back(to, from, 0, 0, G[from].size() - 1);
    }

    ll GetMaxFlow(ll s, ll t)
    {
        count[0] = N - 1;
        count[N] = 1;
        dist[s] = N;
        active[s] = active[t] = true;

        for (auto& edge : G[s])
        {
            excess[s] += edge.cap;
            Push(edge);
        }

        while (!Q.empty())
        {
            ll v = Q.front();
            Q.pop();
            active[v] = false;
            Discharge(v);
        }

        ll totflow = 0;

        for (auto& edge : G[s])
            totflow += edge.flow;

        return totflow;
    }

private:
    ll N;
    std::vector<std::vector<Edge>> G;
    std::vector<ll> excess;
    std::vector<ll> dist, active, count;
    std::queue<ll> Q;

    void Enqueue(ll v)
    {
        if (!active[v] && excess[v] > 0)
        {
            active[v] = true;
            Q.push(v);
        }
    }

    void Push(Edge& e)
    {
        ll amt = std::min<ll>(excess[e.from], e.cap - e.flow);

        if (dist[e.from] <= dist[e.to] || amt == 0)
            return;

        e.flow += amt;
        G[e.to][e.index_of_twin].flow -= amt;
        excess[e.to] += amt;
        excess[e.from] -= amt;
        Enqueue(e.to);
    }

    void Gap(ll k)
    {
        for (ll v = 0; v < N; ++v)
        {
            if (dist[v] < k)
                continue;

            --count[dist[v]];
            dist[v] = std::max(dist[v], N + 1);
            ++count[dist[v]];
            Enqueue(v);
        }
    }

    void Relabel(ll v)
    {
        --count[dist[v]];
        dist[v] = 2*N;

        for (auto& edge : G[v])
        {
            if (edge.cap - edge.flow > 0)
                dist[v] = std::min(dist[v], dist[edge.to] + 1);
        }

        ++count[dist[v]];
        Enqueue(v);
    }

    void Discharge(ll v)
    {
        for (auto& edge : G[v])
        {
            if (excess[v] <= 0)
                break;
            Push(edge);
        }

        if (excess[v] > 0)
        {
            if (count[dist[v]] == 1)
                Gap(dist[v]);
            else
                Relabel(v);
        }
    }
};
