import QtQuick 2.0

//![0]
ListView {
    width: 200; height: 250

    model: stuModel
    delegate: Row{
        Text { text: "Ho va ten " + name }
        Text { text: "Tuoi:  " + age }
        Text { text: "Gioi tinh " + sex }
        Text { text: "Email " + email }
        Text { text: "Dia chi " + address }
        Text { text: "So DT " + mobilNumber }
    }
}
//![0]
