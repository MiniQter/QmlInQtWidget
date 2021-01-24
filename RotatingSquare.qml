import QtQuick 2.15

Rectangle {
    id: root

    signal signalFromQml
    signal responseSignalFromCpp

    function functionInQml() {
        console.log("call qml function.")
    }

    onResponseSignalFromCpp: {
        console.log("response signal from cpp.")
    }

    MouseArea {
        anchors.fill: parent
        onClicked: root.signalFromQml()
    }

    Rectangle {
        id: square

        property int d: 100

        width: d
        height: d
        anchors.centerIn: parent
        color: "red"

        NumberAnimation on rotation {
            from: 0
            to: 360
            duration: 2000
            loops: Animation.Infinite
        }
    }

    Text {
        anchors.centerIn: parent
        text: "Qt Quick running in a widget"
    }
}
