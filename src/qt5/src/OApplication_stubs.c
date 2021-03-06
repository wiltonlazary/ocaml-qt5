#include <QApplication>

#include "OApplication.h"

#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <cassert>

OApplication::OApplication() {
    DEBUG("%p [0x%lx]->%s\n", this, maybe_obj(), __PRETTY_FUNCTION__);
}

OApplication::~OApplication() {
    DEBUG("%p [0x%lx]->%s\n", this, maybe_obj(), __PRETTY_FUNCTION__);
}


extern "C" value caml_mrvn_QT5_OApplication_exec() {
  CAMLparam0();
  DEBUG("%s()\n", __PRETTY_FUNCTION__);
  CAMLreturn(Val_int(QApplication::exec()));
}

extern "C" value caml_mrvn_QT5_OApplication_quit(OClass *obj) {
    CAMLparam0();
    DEBUG("%s(%p)\n", __PRETTY_FUNCTION__, obj);
    QApplication *app = dynamic_cast<QApplication *>(obj);
    assert((app != nullptr) && "not mixed with QApplication");
    app->quit();
    CAMLreturn(Val_unit);
}

extern "C" value caml_mrvn_QT5_OApplication_make(value ml_args) {
  CAMLparam1(ml_args);
  DEBUG("%s(0x%lx)\n", __PRETTY_FUNCTION__, ml_args);
  OQApplication *app = new OQApplication(ml_args);
  assert(app != nullptr);
  DEBUG("%s = %p\n", __PRETTY_FUNCTION__, app);
  CAMLreturn(value(static_cast<OClass *>(app)));
}
