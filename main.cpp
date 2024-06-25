#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

// Функция для вычисления НОД двух чисел
int nod(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class NODWidget : public QWidget {
    Q_OBJECT

public:
    NODWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *mainLayout = new QVBoxLayout(this);

        // Первая строка ввода
        QHBoxLayout *inputLayout1 = new QHBoxLayout();
        QLabel *label1 = new QLabel("Число 1:");
        input1 = new QLineEdit();
        inputLayout1->addWidget(label1);
        inputLayout1->addWidget(input1);

        // Вторая строка ввода
        QHBoxLayout *inputLayout2 = new QHBoxLayout();
        QLabel *label2 = new QLabel("Число 2:");
        input2 = new QLineEdit();
        inputLayout2->addWidget(label2);
        inputLayout2->addWidget(input2);

        // Кнопка для вычисления НОД
        QPushButton *calcButton = new QPushButton("Вычислить НОД");
        connect(calcButton, &QPushButton::clicked, this, &NODWidget::calculateNOD);

        // Третье окно для вывода результата
        QHBoxLayout *outputLayout = new QHBoxLayout();
        QLabel *label3 = new QLabel("НОД:");
        result = new QLineEdit();
        result->setReadOnly(true);
        outputLayout->addWidget(label3);
        outputLayout->addWidget(result);

        // Добавляем все компоненты в основной layout
        mainLayout->addLayout(inputLayout1);
        mainLayout->addLayout(inputLayout2);
        mainLayout->addWidget(calcButton);
        mainLayout->addLayout(outputLayout);
    }

private slots:
    void calculateNOD() {
        bool ok1, ok2;
        int num1 = input1->text().toInt(&ok1);
        int num2 = input2->text().toInt(&ok2);

        if (ok1 && ok2) {
            int resultNOD = nod(num1, num2);
            result->setText(QString::number(resultNOD));
        } else {
            QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите корректные числа");
        }
    }

private:
    QLineEdit *input1;
    QLineEdit *input2;
    QLineEdit *result;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    NODWidget window;
    window.setWindowTitle("Вычисление НОД");
    window.show();

    return app.exec();
}

#include "main.moc"
