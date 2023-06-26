import QtQuick 2.15
import QtQuick.Window 2.15


Window {
    width: 1920
    height: 1080
    visible: true
    visibility: "FullScreen"

    Rectangle {
        id: playerUIContainer
        anchors.centerIn: parent
        width: parent.width - 100
        height: parent.height - 100
        color: "#708090"
    }
}
