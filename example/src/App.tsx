import * as React from 'react';
import { StyleSheet, View, Text } from 'react-native';
import Mobits, { MobitsClient } from 'react-native-mobits';

const garage = 262;
const track = '16520ec2-6106-43c9-a709-ece1abd01e94';

const client: MobitsClient = {
  firstName: 'teste',
  lastName: 'teste',
  document: '09389416906',
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
