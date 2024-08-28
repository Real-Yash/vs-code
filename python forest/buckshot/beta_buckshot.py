import random
import time

def initialize_game(round_num):
    """Initialize the game for the given round number."""
    if round_num == 1:
        return 2, 2  # Hearts for player and dealer
    elif round_num == 2:
        return 4, 4
    elif round_num == 3:
        return 5, 5
    return 0, 0

def load_shotgun(num_live_shells):
    """Load the shotgun with a certain number of live shells and blanks."""
    shells = ['live'] * num_live_shells + ['blank'] * (6 - num_live_shells)
    random.shuffle(shells)
    return shells

def display_bullet_info(shells):
    """Display the number of live shells and blanks in the shotgun."""
    live_count = shells.count('live')
    blank_count = shells.count('blank')
    print(f"\nThe shotgun contains {len(shells)} shells:")
    print(f" - Live shells: {live_count}")
    print(f" - Blank shells: {blank_count}")

def shoot(shells, current_index):
    """Perform a shot and return whether it was a live shell or blank."""
    return shells[current_index] == 'live'

def print_status(player_hearts, dealer_hearts):
    """Print the current status of hearts."""
    print(f"\nPlayer hearts: {player_hearts}")
    print(f"Dealer hearts: {dealer_hearts}")

def print_colored(text, color_code):
    """Print text in a specific color."""
    print(f"\033[{color_code}m{text}\033[0m")

def player_turn(shells, current_index):
    """Handle the player's turn."""
    print_colored("\nYour turn:", '93')  # Yellow
    print("Choose action:")
    print("0 - Shoot yourself")
    print("1 - Shoot the dealer")
    choice = input("Enter your choice (0 or 1): ").strip()
    
    if choice not in ['0', '1']:
        print("Invalid choice. Try again.")
        return None  # Invalid input

    if choice == '0':
        # Player shoots themselves
        if shoot(shells, current_index):
            return 'player', 'live'
        else:
            return 'player', 'blank'
                
    elif choice == '1':
        # Player shoots the dealer
        if shoot(shells, current_index):
            return 'dealer', 'live'
        else:
            return 'dealer', 'blank'

def dealer_turn(shells, current_index):
    """Simulate the Dealer's turn."""
    print_colored("\nDealer's turn:", '93')  # Yellow
    choice = random.choice(['0', '1'])  # Randomly choose to shoot self or player
    if choice == '0':
        # Dealer shoots themselves
        if shoot(shells, current_index):
            return 'dealer', 'live'
        else:
            return 'dealer', 'blank'
    elif choice == '1':
        # Dealer shoots the player
        if shoot(shells, current_index):
            return 'player', 'live'
        else:
            return 'player', 'blank'

def play_round(round_num):
    """Play a round of the game."""
    player_hearts, dealer_hearts = initialize_game(round_num)
    
    # Determine the number of live shells based on round
    num_live_shells = round_num + 1  # Simplified shell count logic
    shells = load_shotgun(num_live_shells)
    
    display_bullet_info(shells)
    
    current_index = 0
    while player_hearts > 0 and dealer_hearts > 0:
        # Player's turn
        result = player_turn(shells, current_index)
        if result is None:
            continue  # Invalid choice, prompt again

        target, shot_type = result
        if target == 'player':
            if shot_type == 'live':
                player_hearts -= 1
                print_colored("\nOuch! You shot yourself with a live shell!", '91')  # Red
            else:
                print_colored("\nPhew! It was a blank.", '92')  # Green
                
        elif target == 'dealer':
            if shot_type == 'live':
                dealer_hearts -= 1
                print_colored("\nBang! The dealer got shot with a live shell!", '92')  # Green
            else:
                print_colored("\nMissed! It was a blank.", '91')  # Red
        
        # Move to the next shell
        current_index = (current_index + 1) % len(shells)
        
        # Print status
        print_status(player_hearts, dealer_hearts)
        
        # Check for round end conditions
        if player_hearts == 0:
            print_colored("\nYou have lost all your hearts. Dealer wins this round!", '91')  # Red
            return False
        if dealer_hearts == 0:
            print_colored("\nDealer has lost all their hearts. You win this round!", '92')  # Green
            return True

        # Dealer's turn
        result = dealer_turn(shells, current_index)
        target, shot_type = result
        if target == 'player':
            if shot_type == 'live':
                player_hearts -= 1
                print_colored("\nBang! The dealer shot you with a live shell!", '91')  # Red
            else:
                print_colored("\nThe dealer missed! It was a blank.", '92')  # Green
        elif target == 'dealer':
            if shot_type == 'live':
                dealer_hearts -= 1
                print_colored("\nOuch! The dealer shot themselves with a live shell!", '91')  # Red
            else:
                print_colored("\nThe dealer used a blank.", '92')  # Green
        
        # Move to the next shell
        current_index = (current_index + 1) % len(shells)
        
        # Print status
        print_status(player_hearts, dealer_hearts)
        
        # Check for round end conditions
        if player_hearts == 0:
            print_colored("\nYou have lost all your hearts. Dealer wins this round!", '91')  # Red
            return False
        if dealer_hearts == 0:
            print_colored("\nDealer has lost all their hearts. You win this round!", '92')  # Green
    
    return False

def main():
    """Main function to run the game."""
    for round_num in range(1, 4):
        print(f"\n--- Round {round_num} ---")
        if not play_round(round_num):
            print("Game Over!")
            break
        print("\nMoving to the next round...\n")

    print("Thanks for playing!")

if __name__ == "__main__":
    main()
