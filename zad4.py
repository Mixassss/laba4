import random

class Player:
    def __init__(self):
        self.score = 0
        self.moves = []

    def make_move(self, previous_moves):
        pass

class Betrayer(Player):
    def make_move(self, previous_moves):
        return 'betray'

class Cooperator(Player):
    def make_move(self, previous_moves):
        return 'cooperate'

class RandomPlayer(Player):
    def make_move(self, previous_moves):
        return random.choice(['betray', 'cooperate'])

class Game:
    def __init__(self, player1, player2):
        self.player1 = player1
        self.player2 = player2
        self.rounds = random.randint(100, 200)

    def play_round(self, moves):
        if moves[0] == 'betray' and moves[1] == 'betray':
            return 4, 4
        elif moves[0] == 'cooperate' and moves[1] == 'betray':
            return 0, 20
        elif moves[0] == 'cooperate' and moves[1] == 'cooperate':
            return 24, 24
        else:
            return 20, 0

    def play_game(self):
        for _ in range(self.rounds):
            moves = [self.player1.make_move(self.player2.moves), self.player2.make_move(self.player1.moves)]
            self.player1.moves.append(moves[1])
            self.player2.moves.append(moves[0])
            p1_score, p2_score = self.play_round(moves)
            self.player1.score += p1_score
            self.player2.score += p2_score

        return self.player1.score, self.player2.score

# Создаем игроков
player1 = Betrayer()
player2 = Cooperator()
player3 = RandomPlayer()

# Создаем игру
game = Game(player1, player2)
# Играем
score1, score2 = game.play_game()

print("Результаты игры:")
print(f"Игрок 1: {score1} очков")
print(f"Игрок 2: {score2} очков")
