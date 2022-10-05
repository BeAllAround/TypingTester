    let _show = false
    let _id = setInterval(()=>{ // detect input
      if(!_show) {
        let input = document.querySelector('#saveCollect')
        if(input) {
          console.log('input mounted: ', input)
          input.addEventListener('input', e=>{
            let found = this.collectionAssets.map(asset=>asset.id).find(v=>v==e.target.value)
            if(found) {
              Object.assign(input.style, {'border': '1px solid red',})
              let div = document.createElement('div')
              div.id = 'used'
              div.textContent = 'used'
              Object.assign(div.style, {})
              input.parentNode.appendChild(div)
            } 
            else {
              Object.assign(input.style, {'border': '1px solid #4a8ccc',})
              if(input.parentNode.lastChild.id == 'used') {
                input.parentNode.lastChild.remove()
              }
            }

            console.log('changed!::', e.target.value, this.collectionAssets.map(asset=>asset.id))
          })
          clearInterval(_id)
          _show = true
        }
      }
    }, 11)
