# React Native Mobits.
![npm](https://img.shields.io/badge/npm-0.0.1-blueviolet?style=for-the-badge)

<h2 style="color:#FF3728">
  ! Not supported on IOS 
  <span style="color:#FFE756">
    ( under implementation )
  </span>
  and Windows
</h2>

## Instalation
---
```
npm install --save react-native-mobits
```
or
```
yarn add react-native-mobits
```
## Usage
---

```tsx
import React, { useCallback, useMemo } from 'react'
import { View, Text, TouchableOpacity, StyleSheet } from 'react-native'
import Mobits from 'react-native-mobits'

const App = () => {
  const garage = useMemo( () => 100, [] )
  const track = useMemo( () => 'tracker-id', [] )
  const client = useMemo( () => ( {
    firstName: 'ze',
    lastName: '',
    document: ''
  } ), [] )

  const openMobits = useCallback( () => {
    Mobits.open( garage, track, client )
      .then( emitter => {
        /* logic on mobits framework start */
      } )
      .catch( reason => {
        /* error on start framework */
      } )
  }, [] )

  return (
    <View style={ styles.container }>
      <TouchableOpacity style={ styles.button } onPress={openMobits}>
        <Text style={ styles.buttonText }>Open Mobits Framework</Text>
      </TouchableOpacity>
    </View>
  )
}

const styles = StyleSheet.create( {
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  button: {
    paddingVertical: 10,
    paddingHorizontal: 20,
    backgroundColor: '',
  },
  buttonText: {
    alignText: 'center'
  }
} )

export default App
```
## Events
---
- `payment`: receive payment infomation with success.
- `payment-error`: receive error of payment failed.
- `auth`: receive token, code and key of authentication.
- `auth-error`: receive error of authentication failed.
- `card`: receive card information in payment.
- `open`: receive description of scrren in screen open.
- `start`: receive time of mobits framework start.

## Events Example
---
### Payment
```ts
type PaymentInfo = [ ( string )?, ( string )?, ( string )?, ( string )?, ( string )?, ( string )?, ( string )?, ( string )?, ( string )?, ( string )?, ( string )?, ( string )? ]

Mobits.on( 'payment', ( ...args: PaymentInfo ) => {
  /* payment receive */
} )
Mobits.on( 'payment-error', ( error: Error ) => {
  /* payment error receive */
} )
```

### Authentication
```ts
Mobits.on( 'auth', ( token: string, code: string, key: string ) => {
  /* authentication receive */
} )
Mobits.on( 'auth-error', ( error: Error ) => {
  /* authentication error receive */
} )
```

### Card Information
```ts
type CardInfo = [ ( string )?, ( string )? ]

Mobits.on( 'card', ( ...args: CardInfo ) => {
  /* card information receive */
} )
```

### Mobits Framework Events
```ts
Mobits.on( 'open', ( ...args: string[] ) => {
  /* mobits screen open */
} )
Mobits.on( 'start', ( time: number ) => {
  /* mobits framework start */
} )
```

### Client Events in Framework
```ts
Mobits.on( 'client-event', ( event?: string, ...args: string[] ) => {
  /* internal client event */
} )

let clientEvent: string
Mobits.on( clientEvent, ( ...args: string[] ) => {
  /* internal client event */
} )
```

## License
---
React Native Mobits is MIT licensed, as found in the [LICENSE](https://github.com/korbantech/react-native-mobits/blob/master/LICENSE) file