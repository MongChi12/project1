#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}

void printMenu() {
    cout << "\n<���� ���� �ý���>\n"
        << "1. HP ȸ��\n"
        << "2. MP ȸ��\n"
        << "3. HP ��ȭ\n"
        << "4. MP ��ȭ\n"
        << "5. ���� ��ų ���\n"
        << "6. �ʻ�� ���\n"
        << "7. ������\n"
        << "��ȣ�� �������ּ���: ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int status[4] = { 0, 0, 0, 0 }; // 0:HP, 1:MP, 2:ATK, 3:DEF

    while (true) {
        cout << "HP�� MP�� �Է����ּ���: ";
        cin >> status[0] >> status[1];
        if (status[0] > 50 && status[1] > 50) break;
        cout << "HP�� MP�� ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���.\n";
    }

    while (true) {
        cout << "���ݷ°� ������ �Է����ּ���: ";
        cin >> status[2] >> status[3];
        if (status[2] > 0 && status[3] > 0) break;
        cout << "���ݷ�/������ 0���� Ŀ�� �մϴ�. �ٽ� �Է����ּ���.\n";
    }

    int hpPotion = 0, mpPotion = 0;
    setPotion(5, &hpPotion, &mpPotion);
    cout << "* ������ ���޵Ǿ����ϴ�. (HP, MP ���� �� 5��)\n";

    while (true) {
        printMenu();
        int sel;
        if (!(cin >> sel)) break;

        switch (sel) {
        case 1: { // HP ȸ��: +20, HP ���� -1
            if (hpPotion <= 0) {
                cout << "������ �����մϴ�.\n";
                break;
            }
            status[0] += 20;
            hpPotion--;
            cout << "* HP�� 20 ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�.\n";
            cout << "���� HP: " << status[0] << "\n���� ���� ��(HP): " << hpPotion << '\n';
            break;
        }
        case 2: { // MP ȸ��: +20, MP ���� -1
            if (mpPotion <= 0) {
                cout << "������ �����մϴ�.\n";
                break;
            }
            status[1] += 20;
            mpPotion--;
            cout << "* MP�� 20 ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�.\n";
            cout << "���� MP: " << status[1] << "\n���� ���� ��(MP): " << mpPotion << '\n';
            break;
        }
        case 3: { // HP ��ȭ: 2��
            status[0] *= 2; 
            cout << "* HP�� 2��� �����Ǿ����ϴ�.\n���� HP: " << status[0] << '\n';
            break;
        }
        case 4: { // MP ��ȭ: 2��
            status[1] *= 2; 
            cout << "* MP�� 2��� �����Ǿ����ϴ�.\n���� MP: " << status[1] << '\n';
            break;
        }
        case 5: { 
            if (status[1] < 50) {
                cout << "��ų ����� �Ұ����մϴ�. (MP ����)\n";
            }
            else {
                status[1] -= 50;
                cout << "* ��ų�� ����Ͽ� MP�� 50 �Ҹ�Ǿ����ϴ�.\n���� MP: " << status[1] << '\n';
            }
            break;
        }
        case 6: { 
            int cost = status[1] / 2;
            if (cost == 0) {
                cout << "�ʻ�� ����� �Ұ����մϴ�. (MP ����)\n";
            }
            else {
                status[1] -= cost;
                cout << "* �ʻ�⸦ ����Ͽ� MP�� " << cost << " �Ҹ�Ǿ����ϴ�.\n���� MP: " << status[1] << '\n';
            }
            break;
        }
        case 7:
            cout << "���α׷��� �����մϴ�.\n";
            return 0;
        default:
            cout << "�ùٸ� ��ȣ�� �Է����ּ���.\n";
        }
    }
    return 0;
}
