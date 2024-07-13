// Include necessary Qt headers
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include "encryption_with_key.hpp"

// Define global map and key
std::unordered_map<std::string, std::string> users;
const std::string encryption_key = "my_secret_key";

class LoginWidget : public QWidget {
    Q_OBJECT
public:
    LoginWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        usernameLineEdit = new QLineEdit(this);
        passwordLineEdit = new QLineEdit(this);
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        QPushButton *registerButton = new QPushButton("Register", this);
        QPushButton *loginButton = new QPushButton("Login", this);
        QLabel *outputLabel = new QLabel(this);

        layout->addWidget(new QLabel("Username:", this));
        layout->addWidget(usernameLineEdit);
        layout->addWidget(new QLabel("Password:", this));
        layout->addWidget(passwordLineEdit);
        layout->addWidget(registerButton);
        layout->addWidget(loginButton);
        layout->addWidget(outputLabel);

        connect(registerButton, &QPushButton::clicked, this, &LoginWidget::handleRegister);
        connect(loginButton, &QPushButton::clicked, this, &LoginWidget::handleLogin);

        this->setLayout(layout);
    }

public slots:
    void handleRegister() {
        std::string username = usernameLineEdit->text().toStdString();
        std::string password = passwordLineEdit->text().toStdString();

        std::string encrypted_password = password;
        vix::cryption(encrypted_password, encryption_key);
        users[username] = encrypted_password;

        outputLabel->setText("User registered successfully!");
    }

    void handleLogin() {
        std::string username = usernameLineEdit->text().toStdString();
        std::string password = passwordLineEdit->text().toStdString();

        auto it = users.find(username);
        if (it != users.end()) {
            std::string encrypted_password = password;
            vix::cryption(encrypted_password, encryption_key);
            if (encrypted_password == it->second) {
                outputLabel->setText("Login successful!");
                return;
            }
        }
        outputLabel->setText("Login failed!");
    }

private:
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *outputLabel;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    LoginWidget loginWidget;
    loginWidget.show();

    return app.exec();
}

#include "main.moc"
