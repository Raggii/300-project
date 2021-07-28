import { StatusBar } from 'expo-status-bar';
import React, {useState} from 'react';
import { StyleSheet, Text, View, Button } from 'react-native';
import SecondPage from './SecondPage';
import ThirdPage from './ThirdPage';

export default function App() {


  const [number, setNumber] = useState(0);
  const [page, setPage] = useState(0);
  function Increment() {
    setNumber(number +1);
  }
  function Decrement() {
    setNumber(number -1);
  }


  return (
    <View style={styles.container}>
      <View>
        <Text>This is my fun testing app</Text>
        <Text>Its all Text and Veiws</Text>
        <View style={styles.button}>
          <Button
          onPress={Increment}
          title="Increment"        
        ></Button>
        <Button
          onPress={Decrement}
          title="Decrement"
        ></Button>
        </View>
        
      </View>
      <View>
        <Text style={styles.number}>
          {number}
        </Text>
      </View>
      <View style={styles.second}>
        <Text>Changing screeeeeen</Text>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    textAlign: 'center',
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
    backgroundColor: '#e1e1e1',
  },
  button: {
    marginLeft: 50,
    marginRight: 50,
    marginTop: 20,
  },
  number: {
    fontSize: 50,
    
  },
  second: {
    marginTop: 20,

  }

});
