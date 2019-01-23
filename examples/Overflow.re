open Revery.UI;
open Revery.Core;
open Revery.UI.Components;

let containerStyle =
  Style.[
    position(`Absolute),
    top(0),
    bottom(0),
    left(0),
    right(0),
    alignItems(`Center),
    justifyContent(`Center),
    flexDirection(`Column),
    backgroundColor(Colors.black),
  ];

let outerBox =
  Style.make(
    ~width=150,
    ~height=150,
    ~overflow=LayoutTypes.Hidden,
    ~backgroundColor=Colors.red,
    (),
  );

let innerBox =
  Style.make(
    ~width=450,
    ~height=450,
    ~backgroundColor=Color.rgba(0., 1.0, 0., 0.5),
    (),
  );

module Sample = {
  let component = React.component("Sample");

  let make = () =>
    component(slots => {
      let (hidden, setHidden, _slots: React.Hooks.empty) =
        React.Hooks.state(false, slots);

      let outerStyle =
        List.append(
          outerBox,
          [
            Style.overflow(hidden ? LayoutTypes.Scroll : LayoutTypes.Visible),
          ],
        );

      let onClick = _ => setHidden(!hidden);

      <View style=containerStyle>
        <ScrollView style=outerStyle>
            <View
              style={innerBox}
            />
        </ScrollView>
        <View style={Style.make(~marginTop=80, ())}>
          <Button fontSize=20 height=45 title="Toggle overflow" onClick />
        </View>
      </View>;
    });

  let createElement = (~children as _, ()) => React.element(make());
};

let render = () => <Sample />;
