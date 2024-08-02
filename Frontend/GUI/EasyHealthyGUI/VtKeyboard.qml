import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.VirtualKeyboard 2.15

/**<InputPanel to create a custom keyboard that slides
    up and down when the keyboard is shown or hidden.*/
Rectangle {
    id: window
    width: 800
    height: 260
    color: "#0a0a0a"
    signal keyboardchanged(bool active)
    InputPanel {
        id: inputPanel
        z: 99
        x: 0
        y: window.height
        width: window.width

        /**<Signal send to the stackedWidget that indicates the keyboard state*/
        onActiveChanged: {
            window.keyboardchanged(inputPanel.active)
        }

        states:[
            State {
                name: "visible"
                when: inputPanel.active
                PropertyChanges {
                    target: inputPanel
                    y: window.height - inputPanel.height
                }
            }
        ]

        transitions: Transition {
            from: ""
            to: "visible"
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "y"
                    duration: 10
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }
}
