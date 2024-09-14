class Country:
    def __init__(self):
        self.nationality = ""
    
    def accept_nationality(self):
        # Method to accept a string from the user
        self.nationality = input("Enter the nationality: ")
    
    def print_nationality(self):
        # Method to print the nationality
        print(f"Nationality: {self.nationality}")

class State(Country):
    def __init__(self):
        super().__init__()
        self.state_name = ""
    
    def accept_state(self):
        # Method to accept a state name from the user
        self.state_name = input("Enter the state name: ")
    
    def print_state(self):
        # Method to print the state
        print(f"State: {self.state_name}")

def print_details(state_obj):
    # Method to print state, country, and nationality
    state_obj.print_state()
    state_obj.print_nationality()
    print(f"Country: {state_obj.__class__.__name__}")

# Example usage
state_obj = State()

# Accept inputs
state_obj.accept_nationality()
state_obj.accept_state()

# Print details
print_details(state_obj)
