def test2():
    f = open("test2.txt", "w")

    for r in range(6):
        for c in range(5):
            for i in range(ord('a'), ord('z')+1):
                smallLetter = chr(i)
                capLetter = chr(i - ord('a') + ord('A'))
                f.write(f"""
    KEY_PRESS({capLetter});
    QCOMPARE(BOX({r}, {c})->getLetter(), '{smallLetter}');
    DEL_PRESS;
    QCOMPARE(BOX({r}, {c})->getLetter(), ' ');
    """)
            f.write(f"KEY_PRESS({('APPLE')[c]});\n")
        if (r < 5):
            f.write("ENT_PRESS;\n")

    f.close()

color_dict = {
    "G": "GREEN",
    "Y": "YELLOW",
    "H": "GREY"
}
ob = "{"
pb = "}"
def test22():
    f = open("test22.txt", "w")

    test22.row = 0
    test22.num = 0
    def header(ans):
        test22.num += 1
        test22.row = 0
        f.write(f'''
curRound.
curRound.wr->setAnswer("{ans.lower()}");\n''')
    def enter_word(word, colors):
        [f.write(f"KEY_PRESS({c.upper()});\nQCOMPARE(BOX({test22.row}, {i})->getLetter(), '{c.lower()}');\n") for i, c in enumerate(word)]
        f.write("ENT_PRESS;\n")
        [f.write(f'QCOMPARE(curRound.ui->centralwidget->findChild<Key*>("toolButton_{c.upper()}")->getColor(), {color_dict[color.upper()]});\n') for c, color in zip(word, colors)]
        test22.row += 1
    header("award")
    enter_word("blend", "hhhhg")
    enter_word("pants", "hyhhh")
    enter_word("param", "hyyyh")
    enter_word("after", "ghhhy")
    enter_word('alarm', 'ghggh')
    enter_word("award", "ggggg")
    header('rooms')
    enter_word('braid', "hyhhh")
    enter_word('round', 'gghhh')
    enter_word('mourn', 'yghgh')
    enter_word('plots', 'hhghg')
    enter_word('odors', 'ghggg')
    enter_word('rooms', 'ggggg')
    
    f.close()
    


# ------------

def main():
    test2()
    test22()

if __name__ == "__main__":
    main()