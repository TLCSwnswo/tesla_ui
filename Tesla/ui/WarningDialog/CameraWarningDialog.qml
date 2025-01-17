import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.13

Dialog {
    id: cameraWarningDialog
    title: "cameraWarning"
    x: (parent.width - width) / 4
    y: (parent.height - height) / 4
    width: 800
    height: 600
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

    background: Rectangle {
        id: dialogBackground
        color: "white"
        radius: 5
    }
    ColumnLayout {
        Image{
            id: opencvImage
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            property bool counter: false
            visible: false
            source: "image://live/image"
            asynchronous: false
            cache: false

            function reload()
            {
                counter = !counter
                source = "image://live/image?id=" + counter
            }

        }

        Button{
            id: startButton
            x: imageRect.x/2 - startButton.width/2
            y:imageRect.height/6 + imageRect.y
            text: "Open"

            onClicked: {
                VideoStreamer.openVideoCamera(videoPath.text)
                opencvImage.visible = true
            }
        }

        TextField{
            id:videoPath
            x: startButton.x - startButton.width
            y: startButton.y + startButton.height * 2
            placeholderText: "Video Path or Video Index"
            cursorVisible: true

            width: startButton.width * 3
        }

        Button {
            text: "OK"
            Layout.alignment: Qt.AlignHCenter
            onClicked: warningDialog.close()
        }

        Connections{
            target: liveImageProvider

            function onImageChanged()
            {
                opencvImage.reload()
            }

        }
    }
}
