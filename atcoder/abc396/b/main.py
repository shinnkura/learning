import sys

def process_queries(queries):
    stack = [0] * 100
    for query in queries:
        if query[0] == 1:
            stack.append(query[1])
        else:
            print(stack.pop())


if __name__ == "__main__":
    Q = int(sys.stdin.readline().strip())
    queries = [list(map(int, sys.stdin.readline().split())) for _ in range(Q)]
    process_queries(queries)
