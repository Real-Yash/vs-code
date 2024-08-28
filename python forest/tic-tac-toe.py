# Tic Tac Toe Game with User Interface for Two Players

# Import the necessary library
import tkinter as tk


# Create the main game window
root = tk.Tk()
root.title("Tic Tac Toe")

# Create the game board
board = [
    ["", "", ""],
    ["", "", ""],
    ["", "", ""]
]

# Create the game status
game_over = False
winner = None
current_player = "X"

# Create the game board UI
def draw_board():
    for i in range(3):
        for j in range(3):
            cell = tk.Button(root, text=board[i][j], font=("Arial", 20), width=5, height=2,
                             command=lambda i=i, j=j: handle_click(i, j))
            cell.grid(row=i, column=j)

# Handle player's move
def handle_click(row, col):
    global current_player, game_over, winner
    if board[row][col] == "" and not game_over:
        board[row][col] = current_player
        draw_board()
        if check_winner(current_player):
            winner = current_player
            game_over = True
        elif check_tie():
            winner = "Tie"
            game_over = True
        else:
            current_player = "O" if current_player == "X" else "X"

# Check for winning condition
def check_winner(player):
    for i in range(3):
        if all([cell == player for cell in board[i]]) or all([board[j][i] == player for j in range(3)]):
            return True
    if all([board[i][i] == player for i in range(3)]) or all([board[i][2-i] == player for i in range(3)]):
        return True
    return False

# # Check for tie condition
# def check_tie():
#     return all([cell != "" for row in board for cell in row])


elif check_tie():
    winner = "Tie"
    game_over = True
    print("It's a tie!")  # Add this line to announce a tie
else:
    current_player = "O" if current_player == "X" else "X"

# Check for winning condition
def check_winner(player):
    for i in range(3):
        if all([cell == player for cell in board[i]]) or all([board[j][i] == player for j in range(3)]):
            print(f"Player {player} wins!")  # Add this line to announce the winner
            return True
    if all([board[i][i] == player for i in range(3)]) or all([board[i][2-i] == player for i in range(3)]):
        print(f"Player {player} wins!")  # Add this line to announce the winner
        return True
    return False
# Draw the initial game board
draw_board()

# Run the game
root.mainloop()
