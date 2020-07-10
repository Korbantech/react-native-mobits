import * as React from 'react';
import { StyleSheet, View, Text } from 'react-native';
import Mobits, { MobitsClient } from 'react-native-mobits';

const garage = 0;
const track = '';

const client: MobitsClient = {
  firstName: 'teste',
  lastName: 'teste',
  document: '00000000000',
};

export default function App() {
  React.useEffect(() => {
    Mobits.open(garage, track, client);
  }, []);

  return (
    <View style={styles.container}>
      <Text>Mobits start</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
});
