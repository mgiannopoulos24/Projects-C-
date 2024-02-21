#include <iostream>
#include <vector>

class Cashier {
private:
    bool openFlag;
    int customersServed;
    const int L; // Threshold for closing due to overwork

public:
    Cashier(int threshold = 10) : openFlag(false), customersServed(0), L(threshold) {}

    void open() {
        openFlag = true;
        customersServed = 0;
        std::cout << "Cashier opened." << std::endl;
    }

    void close() {
        openFlag = false;
        std::cout << "Cashier closed." << std::endl;
    }

    void serve() {
        if (!openFlag) return;
        customersServed++;
        std::cout << "Customer served." << std::endl;
        if (customersServed >= L) {
            close();
            std::cout << "Cashier closed due to overwork." << std::endl;
        }
    }

    bool isOpen() const {
        return openFlag;
    }

    void reset() {
        customersServed = 0;
    }
};

class Bank {
private:
    int lastCustomer;
    int currServing;
    std::vector<Cashier> cashiers;
    const int K;
    int currentCashierIndex;

public:
    Bank(int K, int L) : lastCustomer(0), currServing(0), K(K), currentCashierIndex(0) {
        cashiers = std::vector<Cashier>(5, Cashier(L));
    }

    void enter() {
        if ((lastCustomer - currServing) >= (int)cashiers.size() * K) {
            std::cout << "Sorry, you cannot enter until some customers are served!" << std::endl;
            return;
        }

        lastCustomer++;
        std::cout << "Customer " << lastCustomer << " entered." << std::endl;
        checkToOpen();
    }

    void serve() {
        if (currServing >= lastCustomer) {
            std::cout << "No customers to serve." << std::endl;
            return;
        }

        currServing++;
        bool served = false;
        for (int i = 0; i < cashiers.size(); ++i) {
            int index = (currentCashierIndex + i) % cashiers.size();
            if (cashiers[index].isOpen()) {
                cashiers[index].serve();
                std::cout << "Customer no: " << currServing << " served by cashier no: " << index + 1 << std::endl;
                currentCashierIndex = (index + 1) % cashiers.size(); // Update for next round
                served = true;
                break;
            }
        }

        if (!served) {
            std::cout << "No open cashier to serve customer no: " << currServing << std::endl;
        }
        checkToClose();
    }

    void checkToOpen() {
        int openCashiers = 0;
        for (const auto& cashier : cashiers) {
            if (cashier.isOpen()) openCashiers++;
        }
        if ((lastCustomer - currServing) > openCashiers * K) {
            for (auto &cashier : cashiers) {
                if (!cashier.isOpen()) {
                    cashier.open();
                    return;
                }
            }
        }
    }

    void checkToClose() {
        int neededCashiers = (lastCustomer - currServing) / K + ((lastCustomer - currServing) % K != 0);
        int openCashiers = 0;
        for (auto& cashier : cashiers) {
            if (cashier.isOpen()) openCashiers++;
        }
        if (openCashiers > neededCashiers) {
            for (auto &cashier : cashiers) {
                if (cashier.isOpen()) {
                    cashier.close();
                    if (--openCashiers <= neededCashiers) return;
                }
            }
        }
    }

    int waitingCustomers() const {
        return lastCustomer - currServing;
    }

    void status() {
        std::cout << "Waiting customers: " << waitingCustomers() << std::endl;
        int openCashiers = 0;
        for (const auto& cashier : cashiers) {
            if (cashier.isOpen()) openCashiers++;
        }
        std::cout << "Open cashiers: " << openCashiers << std::endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 5) {
        std::cout << "Usage: " << argv[0] << " K M N L" << std::endl;
        return 1;
    }

    int K = std::stoi(argv[1]);
    int M = std::stoi(argv[2]);
    int N = std::stoi(argv[3]);
    int L = std::stoi(argv[4]);

    Bank bank(K, L);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            bank.enter();
        }
        while (bank.waitingCustomers() > 0) {
            bank.serve();
        }
    }

    bank.status();

    return 0;
}
