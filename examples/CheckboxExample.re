open Revery.Core;
open Revery.UI;
open Revery.UI.Components;

module Check = {
  let component = React.component("Check");
  let make = () => {
    component(slots => {
      let (text, setText, _slots: React.Hooks.empty) =
        React.Hooks.state("Not Checked!", slots);
      <View
        style=Style.[
          width(500),
          height(500),
          justifyContent(`Center),
          alignItems(`Center),
        ]>
        <Checkbox
          onChange={checked => {
            let text = checked ? "Checked!" : "Not Checked!";
            setText(text);
          }}
          style=Style.[marginBottom(10)]
        />
        <Text
          text
          style=Style.[
            marginBottom(10),
            fontFamily("Roboto-Regular.ttf"),
            fontSize(20),
          ]
        />
        <Checkbox style=Style.[border(~width=2, ~color=Colors.green)] />
      </View>;
    });
  };

  let createElement = (~children as _, ()) => React.element(make());
};

let render = () => {
  <Check />;
};