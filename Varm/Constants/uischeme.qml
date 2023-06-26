import QtQuick 2.0
import QtQuick.Window 2.15

Item {

    property int screenWidth: 1920
    property int screenHeight: 1080
    readonly property real refScreenWidth: 1366
    readonly property real refScreenHeight: 768
    function hscale(size) {
        return Math.round(size * (screenWidth / refScreenWidth))
    }

    function vscale(size) {
        return Math.round(size * (screenHeight / refScreenHeight))
    }

    function rscale(size) {
        return Math.round((hscale(size) + vscale(size)) / 2)
    }
}
