#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}

void printMenu() {
    cout << "\n<스탯 관리 시스템>\n"
        << "1. HP 회복\n"
        << "2. MP 회복\n"
        << "3. HP 강화\n"
        << "4. MP 강화\n"
        << "5. 공격 스킬 사용\n"
        << "6. 필살기 사용\n"
        << "7. 나가기\n"
        << "번호를 선택해주세요: ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int status[4] = { 0, 0, 0, 0 }; // 0:HP, 1:MP, 2:ATK, 3:DEF

    while (true) {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> status[0] >> status[1];
        if (status[0] > 50 && status[1] > 50) break;
        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
    }

    while (true) {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> status[2] >> status[3];
        if (status[2] > 0 && status[3] > 0) break;
        cout << "공격력/방어력은 0보다 커야 합니다. 다시 입력해주세요.\n";
    }

    int hpPotion = 0, mpPotion = 0;
    setPotion(5, &hpPotion, &mpPotion);
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)\n";

    while (true) {
        printMenu();
        int sel;
        if (!(cin >> sel)) break;

        switch (sel) {
        case 1: { // HP 회복: +20, HP 포션 -1
            if (hpPotion <= 0) {
                cout << "포션이 부족합니다.\n";
                break;
            }
            status[0] += 20;
            hpPotion--;
            cout << "* HP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n";
            cout << "현재 HP: " << status[0] << "\n남은 포션 수(HP): " << hpPotion << '\n';
            break;
        }
        case 2: { // MP 회복: +20, MP 포션 -1
            if (mpPotion <= 0) {
                cout << "포션이 부족합니다.\n";
                break;
            }
            status[1] += 20;
            mpPotion--;
            cout << "* MP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n";
            cout << "현재 MP: " << status[1] << "\n남은 포션 수(MP): " << mpPotion << '\n';
            break;
        }
        case 3: { // HP 강화: 2배
            status[0] *= 2; 
            cout << "* HP가 2배로 증가되었습니다.\n현재 HP: " << status[0] << '\n';
            break;
        }
        case 4: { // MP 강화: 2배
            status[1] *= 2; 
            cout << "* MP가 2배로 증가되었습니다.\n현재 MP: " << status[1] << '\n';
            break;
        }
        case 5: { 
            if (status[1] < 50) {
                cout << "스킬 사용이 불가능합니다. (MP 부족)\n";
            }
            else {
                status[1] -= 50;
                cout << "* 스킬을 사용하여 MP가 50 소모되었습니다.\n현재 MP: " << status[1] << '\n';
            }
            break;
        }
        case 6: { 
            int cost = status[1] / 2;
            if (cost == 0) {
                cout << "필살기 사용이 불가능합니다. (MP 부족)\n";
            }
            else {
                status[1] -= cost;
                cout << "* 필살기를 사용하여 MP가 " << cost << " 소모되었습니다.\n현재 MP: " << status[1] << '\n';
            }
            break;
        }
        case 7:
            cout << "프로그램을 종료합니다.\n";
            return 0;
        default:
            cout << "올바른 번호를 입력해주세요.\n";
        }
    }
    return 0;
}
