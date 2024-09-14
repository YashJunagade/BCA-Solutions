def remove_odd_index_chars(s):
    # Remove characters at odd indices
    return ''.join(char for index, char in enumerate(s) if index % 2 == 0)

def main():
    user_input = input("Enter a string: ")
    result = remove_odd_index_chars(user_input)
    print(f"Modified string: {result}")

if __name__ == "__main__":
    main()
