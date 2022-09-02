    for (int i=1800; i<3999; i+=17) {
        cout << i;
        for (int j=1; j<=12; j++) {
            cout << " " << starting_dotw(i, j);
        }
        cout << endl;
    }
    return 0;