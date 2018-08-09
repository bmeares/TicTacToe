import random
import os
import platform

def main():
    global numPlayers
    global playerCount
    global table
    global player

    numPlayers = -1
    playerCount = 0
    table = []
    player = ' '

    playing = startScreen()

    for i in range(3):
        table.append([])
        for j in range(3):
            table[i].append(' ')

    while playing:
        playing = state()
        if not playing:
            playing = runAgain()
            for i in range(3):
                for j in range(3):
                    table[i][j] = ' '

def state():
    playing = True
    global playerCount
    global player

    if (playerCount % 2) == 0:
        player = 'X'
    else:
        player = 'O'

    draw()
    turn()

    playing = not checkWin()

    playerCount += 1

    return playing

def startScreen():
    global numPlayers

    clear()
    print("\n Welcome to Tic Tac Toe: Python Edition!\n\n")
    numPlayers = int(input(" How many players for this game?\n (0, 1, or 2): "))

    while numPlayers < 0 or numPlayers > 2:
        numPlayers = int(input("\n Please choose between 0 and 2: "))

    if numPlayers < 2:
        random.seed(a=None)

    return True

def turn():
    picking = True
    global player
    global table
    global numPlayers

    if numPlayers == 2 or ((player == 'X') and (numPlayers == 1)):
        while picking:
            r = row()
            c = col()
            if(table[r][c] != ' '):
                print("\nPlease pick an open square. Enter any key to try again.")
                picking = True
                input("")
                draw()
            else:
                picking = False
        table[r][c] = player

    elif numPlayers < 2:
        randomTurn()


def randomTurn():
    picking = True
    global player

    while picking:
        r = random.randint(0,2)
        c = random.randint(0,2)
        if table[r][c] != ' ':
            picking = True
        else:
            picking = False
    table[r][c] = player
    import time
    time.sleep(0.5)


def row():
    picking = True

    while picking:
        r = int(input("\n Row: "))

        if r > 2 or r < 0:
            print("\n Please choose between 0 and 2. Enter any key to try again.")
            input("")
            draw()
        else:
            picking = False

    return r

def col():
    picking = True

    while picking:
        c = int(input("\n Column: "))

        if c > 2 or c < 0:
            print("\n Please choose between 0 and 2. Enter any key to try again.")
            input("")
            draw()
        else:
            picking = False

    return c


def draw():
    clear()
    global player

    print("\n ", end='')

    for i in range(18):
        print("-", end='')

    print("\n | NOW PLAYING:", player, "|\n ", end='')

    for i in range(18):
        print("-", end='')

    print("\n\n      ", end='')

    for i in range(3):
        print(i, "  ", end='')

    for i in range(3):
        print("\n    ", end='')

        for k in range(13):
            print("-", end='')

        print("\n ", i, "|", end='')

        for j in range(3):
            print("", table[i][j], "|", end='')

    print("\n    ", end='')

    for k in range(13):
        print("-", end='')

    print("\n", end='')

def checkWin():
    global table

    # Check for horizontal victory
    for i in range(3):
        first = table[i][0]
        second = table[i][1]
        third = table[i][2]

        if (first == second == third) and first != ' ':
            draw()
            print("\n", first, "wins!")
            input("")
            return True

    # Check for vertical victory
    for i in range(3):
        first = table[0][i]
        second = table[1][i]
        third = table[2][i]

        if (first == second == third) and first != ' ':
            draw()
            print("\n", first, "wins!")
            input("")
            return True

    # Check for diagonal victory
    if ( ((table[0][0] == table[1][1] == table[2][2]) or
    (table[2][0] == table[1][1] == table[0][2])) and table[1][1] != ' '):
        draw()
        print("\n", table[1][1], "wins!")
        input("")
        return True

    # Check for tie
    spaceAvail = False
    for i in range(3):
        for j in range(3):
            if table[i][j] == ' ':
                spaceAvail = True
    if not spaceAvail:
        spaceAvail = False
        draw()
        print("\n Cat's nest! No one wins.\n")
        input("")
        return True

    return False


def runAgain():
    clear()
    yes = False
    y = input("\n Run again? (y/n): ")

    if y == 'y' or y == 'Y':
        yes = True

    return yes


def clear():
    if platform.system() == "Linux":
        os.system("clear")
    elif platform.system() == "Windows":
        os.system("CLS")
    else:
        print("\033c")


if __name__ == "__main__":
    main()
