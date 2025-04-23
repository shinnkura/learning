def main():
    s = input().strip()
    result = ''.join([c for c in s if c.isupper()])
    print(result)


if __name__ == "__main__":
    main()
